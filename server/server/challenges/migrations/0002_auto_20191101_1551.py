# Generated by Django 2.2.6 on 2019-11-01 19:51

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('challenges', '0001_initial'),
    ]

    operations = [
        migrations.RenameField(
            model_name='challenge',
            old_name='release_time',
            new_name='release_datetime',
        ),
    ]
