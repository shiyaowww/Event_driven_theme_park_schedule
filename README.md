# Event_driven_theme_park_scheme

This is an event-driven simulation of an attraction at a theme park such as Disneyland.
At some theme parks, you can pay an extra fee and get priority access to different attractions. We could use this
simulation to determine the best way to set different aspects of our park, such as:

1. how much to charge for the priority access (charging more means less people will buy the priority access);
2. how often the attraction should accept new riders (more “runs” of the ride can result in higher operating
costs and increased likelihood of breakdown);
3. how many non-priority riders should be allowed on a run even when priority members are waiting (too
many means priority riders get upset and too few means non-priority riders may never get to ride);
4. etc…

Our theme park currently has three levels of priority: “Standard”, “Fast Pass”, and “Super Fast Pass”.
Attractions at our park have a separate line that riders must stand in for each priority. For example, all “Standard”
riders (STD) wait in one line, while “Fast Pass” riders (FP) wait in a second line, and “Super Fast Pass” riders (SFP)
wait in a third line. Attractions are operated by a train of cars, each of which holds some number of riders. When
this train of cars arrives at the attraction’s station, some number of riders from each priority level are allowed on to
enjoy the ride. To make the extra cost worth it for the priority riders, more riders from the SFP line will be admitted
than riders from the FP line (and even fewer from STD). For example, if there are 10 seats available in the cars, we
might allow 6 SFP riders, 3 FP riders and 1 STD rider. For this example, we have:
idealNumSFP = 6, idealNumFP=3, idealNumSTD = 1

When there are lots of riders in each line, this is straightforward, but occasionally there are times when some of the
lines are short or even empty. At these times, we still want to fill up the cars with riders as much as possible, so
additional logic is needed. To keep things as simple as possible, our park’s policy will be as follows: If the ideal
number of each priority level rider is not able to fill up the car, we take as many SFP riders as available to fill up the
car. If there aren’t enough SFP riders to fill it, we take as many FP riders are needed. Finally, if there are not
enough SFP or FP riders, the car is filled up with STD riders.

The ride takes some amount of time, during which, additional riders may arrive and get in the appropriate line.
When a train of cars arrives at the station, the next set of riders is admitted and the process continues until the
park closes. Because we are nice theme park-owners, we don’t want to kick people out as soon as the park closes –
instead, we will stop allowing new rider arrivals, but those in line will get a chance to ride before the ride shuts
down for the evening, meaning that the ride could continue accepting waiting riders well after the official closing
time.
