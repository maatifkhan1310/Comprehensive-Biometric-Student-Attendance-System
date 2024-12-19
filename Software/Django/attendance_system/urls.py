"""
URL configuration for biometric_student_attendance project.
"""

from django.contrib import admin
from django.urls import path, include

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('attendance.urls')),  # Routes to attendance app
]
