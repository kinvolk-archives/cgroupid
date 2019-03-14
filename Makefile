cgroupid: cgroupid.c
	gcc -Wall -static -o cgroupid cgroupid.c

image:
	docker build -t kinvolk/cgroupid .

push:
	docker push kinvolk/cgroupid

clean:
	rm -f cgroupid
