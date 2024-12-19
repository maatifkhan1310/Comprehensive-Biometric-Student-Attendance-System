# Comprehensive-Biometric-Student-Attendance-System

## **Overview**
This repository hosts the implementation of a **Comprehensive Biometric Student Attendance System**. The project integrates a fingerprint sensor with an Arduino for recording attendance and a Django-based web application for managing and monitoring attendance data. 

### **Key Features**
- **Biometric Authentication**: Fingerprint sensor for accurate and secure student identification.
- **Hardware Features**:
  - Adding a new student fingerprint.
  - Removing a student fingerprint.
  - Navigation for up/down menu interactions.

- **Software Features**:
  - Attendance management dashboard.
  - Fingerprint image upload and matching.
  - Reporting and analytics.

---

## **Repository Structure**

### **1. Hardware**
Contains all hardware-related files:
- **`arduino_code/`**: Arduino code for fingerprint sensor functions and navigation.
- **`wiring_diagrams/`**: Circuit diagrams for the setup.
- **`components_list.md`**: Detailed list of components with specifications.

### **2. Software**
Contains the Django-based web application and utility scripts:
- **`django_project/`**: Web application files, including templates, static files, and configurations.
- **`utils/`**: Utility scripts for fingerprint matching and database operations.

### **3. Datasets**
- Example fingerprint data for testing and demonstration purposes.
- Metadata file (`fingerprint_metadata.csv`) to describe fingerprint samples.

### **4. Tests**
Test cases for validating the hardware and software components:
- `test_hardware.md`: Manual test cases for fingerprint sensor functionalities.
- `test_software.md`: Test cases for Django application.
- `integration_tests.md`: Scenarios for testing the end-to-end system.

### **5. Docs**
Documentation for the project:
- `user_manual.md`: Setup and usage guide for the system.
- `integration_guide.md`: Steps to integrate the hardware and software modules.
- `api_documentation.md`: API details for hardware-software communication.

---

## **Setup Instructions**

### **Hardware Setup**
1. Assemble the hardware as per the wiring diagrams in `hardware/wiring_diagrams/`.
2. Upload the appropriate Arduino code (`arduino_code/`) to the microcontroller.
3. Test the sensor using the test cases in `tests/test_hardware.md`.

### **Software Setup**
1. Clone this repository:
         git clone https://github.com/yourusername/comprehensive-biometric-attendance-system.git

2. Navigate to the software folder and install dependencies:
         cd software/django_project/
         pip install -r requirements.txt

3. Run migrations and start the Django server:
         python manage.py migrate
         python manage.py runserver

4. Access the system at http://127.0.0.1:8000/.

---

### **Technologies Used**
- **Hardware:** Arduino, Fingerprint Sensor.
- **Software:** Django, Python, SQLite, Bootstrap.
- **APIs:** Custom APIs for fingerprint matching and data transfer.
