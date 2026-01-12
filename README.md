\# Student Analytics Engine



Student Analytics Engine is a full-stack academic performance analysis system that converts raw student exam data into meaningful insights such as CGPA, risk levels, class average, topper and defaulters — all visualized through a live dashboard.



This project simulates how a real college or university can digitally analyze student performance at scale.



---



\## What This System Does



1\. Teacher uploads a CSV file containing student marks  

2\. A high-performance C engine processes the data  

3\. CGPA and risk levels are calculated automatically  

4\. Results are converted into JSON  

5\. A Python (Flask) API serves the data  

6\. A live web dashboard displays charts and tables  



Everything runs locally but works like a real academic analytics platform.



---



\## Tech Stack



Analytics Engine: C (compiled as main.exe)  

Backend API: Python Flask  

Frontend: HTML, CSS, JavaScript  

Charts: Chart.js  

Data Format: CSV → JSON  



---



\## Project Structure



STUDENT-ANALYTICS-ENGINE  

├── API  

├── DASHBOARD  

├── DATA  

├── OUTPUT  

├── main.exe  

└── README.md  



---



\## How to Run



1\. Go to the API folder  

cd API  



2\. Start the server  

python server.py  



3\. Open browser  

http://127.0.0.1:8765  



4\. Upload a CSV file  

5\. Click Generate Report  

6\. Dashboard will show live analytics  



---



\## CSV Input Format



The CSV file must be in this format:



roll,attendance,mse,tae1,tae2,tae3,tae4,ese  

1,82,15,12,13,11,14,45  

2,76,12,10,11,9,12,40  



Attendance is out of 100  

MSE, TAE and ESE follow real college marking schemes  



---



\## Output



The engine generates JSON reports in the OUTPUT folder:



OUTPUT/classA.json  

OUTPUT/FY\_A.json  



These files are used by the dashboard to render graphs and tables.



---



\## Why This Project Matters



This is not a basic student project.  

It demonstrates:



High-performance data processing in C  

Backend API design  

Real-time frontend visualization  

Real-world academic analytics workflow  



This is how real universities build performance monitoring systems.



---



\## Future Scope



Multi-class support  

Student-wise login  

Cloud deployment  

Mobile app integration  



---



\## Author



Developed as a full-stack academic analytics system by Sufiyan Surve.

