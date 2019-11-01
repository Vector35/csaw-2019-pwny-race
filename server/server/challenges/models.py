from django.db import models

import secrets

def get_upload_name(instance, filename):
    return f"{instance.name}/{secrets.token_hex(16)}/{filename}"


class Challenge(models.Model):
    name = models.CharField(max_length=128)
    description = models.TextField()
    challenge_file = models.FileField(upload_to=get_upload_name)
    release_datetime = models.DateTimeField()
