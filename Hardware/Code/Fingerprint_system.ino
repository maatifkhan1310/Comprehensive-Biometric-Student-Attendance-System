#include <Adafruit_Fingerprint.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// Pin configuration
#define FINGERPRINT_RX 2
#define FINGERPRINT_TX 3
#define UP_BUTTON 4
#define DOWN_BUTTON 5
#define SELECT_BUTTON 6
#define SD_CS_PIN 10

// Fingerprint sensor setup
SoftwareSerial mySerial(FINGERPRINT_RX, FINGERPRINT_TX);
Adafruit_Fingerprint finger(&mySerial);

// Constants and variables
const int maxStudents = 100;
int studentIDs[maxStudents];
int currentStudentCount = 0;
int menuIndex = 0;
String menuOptions[] = {"Mark Attendance", "Add Student", "Remove Student"};
File attendanceFile;

void setup() {
    Serial.begin(9600);
    mySerial.begin(57600);

    // Initialize fingerprint sensor
    if (finger.begin()) {
        Serial.println("Fingerprint sensor initialized successfully.");
    } else {
        Serial.println("Fingerprint sensor initialization failed. Check wiring.");
        while (1);
    }

    // Initialize buttons
    pinMode(UP_BUTTON, INPUT_PULLUP);
    pinMode(DOWN_BUTTON, INPUT_PULLUP);
    pinMode(SELECT_BUTTON, INPUT_PULLUP);

    // Initialize SD card
    if (!SD.begin(SD_CS_PIN)) {
        Serial.println("SD card initialization failed. Check wiring.");
        while (1);
    }
    Serial.println("SD card initialized.");

    // Load stored student IDs
    loadStudentData();

    Serial.println("System ready. Navigate through the menu.");
}

void loop() {
    displayMenu();

    // Navigation logic
    if (digitalRead(UP_BUTTON) == LOW) {
        menuIndex = (menuIndex - 1 + 3) % 3;
        delay(300);
    } else if (digitalRead(DOWN_BUTTON) == LOW) {
        menuIndex = (menuIndex + 1) % 3;
        delay(300);
    } else if (digitalRead(SELECT_BUTTON) == LOW) {
        executeMenuOption(menuIndex);
        delay(300);
    }
}

void displayMenu() {
    Serial.println("\n--- Menu ---");
    for (int i = 0; i < 3; i++) {
        if (i == menuIndex) {
            Serial.print("> ");
        } else {
            Serial.print("  ");
        }
        Serial.println(menuOptions[i]);
    }
}

void executeMenuOption(int index) {
    switch (index) {
        case 0:
            markAttendance();
            break;
        case 1:
            addStudent();
            break;
        case 2:
            removeStudent();
            break;
    }
}

void markAttendance() {
    Serial.println("\nMarking Attendance...");
    int id = getFingerprintID();
    if (id >= 0) {
        Serial.print("Attendance marked for ID: ");
        Serial.println(id);
        recordAttendance(id);
    } else {
        Serial.println("Fingerprint not recognized.");
    }
}

void addStudent() {
    if (currentStudentCount >= maxStudents) {
        Serial.println("\nStudent limit reached.");
        return;
    }

    Serial.println("\nAdding new student. Place finger on the sensor.");
    int id = enrollFingerprint();
    if (id >= 0) {
        studentIDs[currentStudentCount++] = id;
        Serial.print("Student added with ID: ");
        Serial.println(id);
        saveStudentData();
    } else {
        Serial.println("Failed to add student.");
    }
}

void removeStudent() {
    Serial.println("\nRemoving a student. Place finger on the sensor.");
    int id = getFingerprintID();
    if (id >= 0) {
        for (int i = 0; i < currentStudentCount; i++) {
            if (studentIDs[i] == id) {
                for (int j = i; j < currentStudentCount - 1; j++) {
                    studentIDs[j] = studentIDs[j + 1];
                }
                currentStudentCount--;
                Serial.print("Student removed with ID: ");
                Serial.println(id);
                saveStudentData();
                return;
            }
        }
        Serial.println("ID not found in the database.");
    } else {
        Serial.println("Fingerprint not recognized.");
    }
}

int getFingerprintID() {
    if (finger.getImage() != FINGERPRINT_OK) return -1;
    if (finger.image2Tz() != FINGERPRINT_OK) return -1;
    if (finger.fingerFastSearch() != FINGERPRINT_OK) return -1;
    return finger.fingerID;
}

int enrollFingerprint() {
    int id = currentStudentCount + 1;
    Serial.print("Assigning ID: ");
    Serial.println(id);

    if (finger.enrollStart(id) != FINGERPRINT_OK) {
        Serial.println("Enroll start failed.");
        return -1;
    }

    Serial.println("Place the same finger again.");
    while (finger.enroll1() != FINGERPRINT_OK);
    while (finger.enroll2() != FINGERPRINT_OK);
    while (finger.enroll3() != FINGERPRINT_OK);

    Serial.println("Fingerprint enrolled successfully.");
    return id;
}

void loadStudentData() {
    attendanceFile = SD.open("students.txt", FILE_READ);
    if (!attendanceFile) {
        Serial.println("No saved data found.");
        return;
    }

    currentStudentCount = 0;
    while (attendanceFile.available()) {
        studentIDs[currentStudentCount++] = attendanceFile.parseInt();
    }
    attendanceFile.close();
    Serial.println("Student data loaded.");
}

void saveStudentData() {
    attendanceFile = SD.open("students.txt", FILE_WRITE);
    if (!attendanceFile) {
        Serial.println("Failed to save data.");
        return;
    }

    for (int i = 0; i < currentStudentCount; i++) {
        attendanceFile.println(studentIDs[i]);
    }
    attendanceFile.close();
    Serial.println("Student data saved.");
}

void recordAttendance(int id) {
    attendanceFile = SD.open("attendance_log.txt", FILE_WRITE);
    if (!attendanceFile) {
        Serial.println("Failed to log attendance.");
        return;
    }

    attendanceFile.print("ID: ");
    attendanceFile.print(id);
    attendanceFile.print(", Timestamp: ");
    attendanceFile.println(millis());
    attendanceFile.close();
    Serial.println("Attendance recorded.");
}
