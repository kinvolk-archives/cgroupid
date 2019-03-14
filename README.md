# cgroupid

The cgroupid command returns the cgroup ID for the specified path.

Example:
```
$ docker run --privileged -ti --rm -v /sys/fs/cgroup:/sys/fs/cgroup kinvolk/cgroupid /bin/cgroupid /sys/fs/cgroup/unified
4294967297
```
