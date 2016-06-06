#!/bin/bash
for i in {1..10}
do
	DATE=$(date +"%y-%m-%d_%H%M%S");
		echo $DATE;
		sleep 1;
done
