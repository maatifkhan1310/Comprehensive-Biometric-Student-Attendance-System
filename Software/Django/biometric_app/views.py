from django.shortcuts import render, redirect, get_object_or_404
from django.http import HttpResponse
from .models import Student, AttendanceRecord
from django.contrib import messages

def index(request):
    """Homepage view."""
    return render(request, 'index.html')

def students(request):
    """Display the list of students."""
    students = Student.objects.all()
    return render(request, 'students.html', {'students': students})

def add_student(request):
    """Add a new student."""
    if request.method == "POST":
        name = request.POST.get('name')
        roll_number = request.POST.get('roll_number')
        fingerprint_data = request.FILES.get('fingerprint_data')

        if Student.objects.filter(roll_number=roll_number).exists():
            messages.error(request, "A student with this roll number already exists.")
            return redirect('add_student')

        student = Student(name=name, roll_number=roll_number, fingerprint_data=fingerprint_data.read())
        student.save()
        messages.success(request, "Student added successfully.")
        return redirect('students')

    return render(request, 'add_student.html')

def remove_student(request):
    """Remove a student."""
    if request.method == "POST":
        roll_number = request.POST.get('roll_number')
        student = get_object_or_404(Student, roll_number=roll_number)
        student.delete()
        messages.success(request, "Student removed successfully.")
        return redirect('students')

    return render(request, 'remove_student.html')

def attendance(request):
    """Mark attendance."""
    if request.method == "POST":
        roll_number = request.POST.get('roll_number')
        status = request.POST.get('status')
        student = get_object_or_404(Student, roll_number=roll_number)
        AttendanceRecord.objects.create(student=student, status=status)
        messages.success(request, "Attendance recorded successfully.")
        return redirect('attendance')

    records = AttendanceRecord.objects.all()
    return render(request, 'attendance.html', {'records': records})
