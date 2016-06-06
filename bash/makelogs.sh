#!/bin/bash
NOW=$(date +"%Y-%m-%d-%T");
LOGFILE="log-$NOW.txt";
cp /var/log/secure /home/JDD/html/logs/$LOGFILE;
LOGFILE="h-$NOW.txt";
cp /var/log/httpd/access_log /home/JDD/html/logs/$LOGFILE
chmod 755 -R /home/JDD/html/logs/*
