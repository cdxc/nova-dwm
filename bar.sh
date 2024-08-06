while true; do
	xsetroot -name "$(date +%D\ %T) $(cat /sys/class/power_supply/BAT0/capacity)%"
	sleep 1
done
