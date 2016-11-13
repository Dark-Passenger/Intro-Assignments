#!/bin/bash
#
# time_daemon       A timestamp writing daemon
#
# chkconfig: 345 70 30
# description: Time Daemon is a daemon that writes the current time to a file every 5 min.
# processname: time_daemon

# Source function library.
. /etc/init.d/functions

return_value=0
program="time_daemon"
daemon=/bin/$program
LOCKFILE=/var/lock/subsys/$program

start()
{
    echo -n "Starting $program : "
    $daemon
    touch /var/lock/subsys/$program
    return $return_value
}

stop()
{
    echo -n "Shutting down $program : "
    killproc $daemon
    rm -f /var/lock/subsys/$program
    return $return_value
}

case "$1" in
    start)
        start
        ;;
    stop)
        stop
        ;;
    status)
        status $program
        ;;
    restart)
        stop
        start
        ;;
    *)
        echo "Usage: time_daemon {start|stop|status|restart}"
        exit 1
        ;;
esac
exit $?
