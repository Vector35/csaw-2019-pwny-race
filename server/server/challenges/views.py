from django.http import HttpResponse
from django.shortcuts import render
from django.views import generic
from django.utils import timezone
from .models import Challenge


def index(request):
    return render(request, "index.html", )

def challenge_list(request):
    challenges = Challenge.objects.filter(release_datetime__lte=str(timezone.localtime()))
    next_chals = Challenge.objects.filter(release_datetime__gte=str(timezone.localtime()))
    
    next_chal_time = None
    closest_time = None
    for chal in next_chals:
        t = chal.release_datetime.timestamp()
        if closest_time == None or t < closest_time:
            closest_time = t

    return render(request, "index.html", {"challenge_list": challenges, "next_chal_time": closest_time})

