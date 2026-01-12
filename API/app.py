from flask import Flask, render_template, request, send_from_directory, jsonify
import os
import subprocess

app = Flask(__name__, template_folder="../templates")

BASE = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
DATA = os.path.join(BASE, "DATA")
OUTPUT = os.path.join(BASE, "OUTPUT")
ENGINE = os.path.join(BASE, "main.exe")

os.makedirs(DATA, exist_ok=True)
os.makedirs(OUTPUT, exist_ok=True)

print("BASE:", BASE)
print("DATA:", DATA)
print("OUTPUT:", OUTPUT)
print("ENGINE:", ENGINE)
print("SERVER FILE LOADED")

@app.route("/")
def home():
    return render_template("upload.html")

@app.route("/upload", methods=["POST"])
def upload():
    file = request.files["file"]
    save_path = os.path.join(DATA, file.filename)
    file.save(save_path)

    print("Uploaded:", save_path)

    subprocess.run([ENGINE], cwd=BASE)

    return render_template("dashboard.html")

@app.route("/report")
def report():
    files = [f for f in os.listdir(OUTPUT) if f.endswith(".json")]
    if not files:
        return jsonify({"error": "No report generated"})

    latest = max(files, key=lambda f: os.path.getmtime(os.path.join(OUTPUT, f)))
    return send_from_directory(OUTPUT, latest)

@app.route("/OUTPUT/<path:filename>")
def output_files(filename):
    return send_from_directory(OUTPUT, filename)

# FORCE START SERVER
app.run(host="127.0.0.1", port=8765, debug=True)