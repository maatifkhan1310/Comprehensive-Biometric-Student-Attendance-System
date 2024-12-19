"""
WSGI config for biometric_student_attendance project.
"""

import os
from django.core.wsgi import get_wsgi_application

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'biometric_student_attendance.settings')

application = get_wsgi_application()
