# Generated by Django 2.2.6 on 2019-11-01 20:12

import challenges.models
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('challenges', '0002_auto_20191101_1551'),
    ]

    operations = [
        migrations.AlterField(
            model_name='challenge',
            name='challenge_file',
            field=models.FileField(upload_to=challenges.models.get_upload_name),
        ),
    ]
