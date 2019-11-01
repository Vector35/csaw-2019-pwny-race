from django.urls import path, include

from .views import challenge_list

urlpatterns = [
    path('', challenge_list),
]
