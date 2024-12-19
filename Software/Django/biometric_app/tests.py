from django.test import TestCase
from .models import Student, AttendanceRecord

class StudentModelTest(TestCase):
    def setUp(self):
        Student.objects.create(name="John Doe", roll_number="12345")

    def test_student_creation(self):
        student = Student.objects.get(roll_number="12345")
        self.assertEqual(student.name, "John Doe")

class AttendanceRecordTest(TestCase):
    def setUp(self):
        student = Student.objects.create(name="John Doe", roll_number="12345")
        AttendanceRecord.objects.create(student=student, status="Present")

    def test_attendance_record(self):
        record = AttendanceRecord.objects.first()
        self.assertEqual(record.status, "Present")
