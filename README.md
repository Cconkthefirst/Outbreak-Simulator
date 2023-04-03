# Outbreak-Simulator

## Description:
Created as the final for a data structures class, worked in a assigned group of three. The basic idea of the project is to create a simulation of a zombie apocalypse in Simmville. The sim would be able allow the user to set the chances of a denizen becoming infected, the number of days it ran, and how many people live in Simville. Additionally, all of that was supposed to be designed with speed in as one of the prioritized metrics. I was responsible for building the map - meaning all the districts and how they connect to one another and how they are populated. I also was in charge of designing the citizen movement between districts and how they interacted with one another. Lastly, I was tasked with building out the simulator class and how it runs through hours, days, and weeks.

---

## Lessons: 
1.) I would have used a vector to store population instead of a linked list because they are more efficient when needing to randomly access it data, iterate over its contents, and they are easier on memory.

2.) Learned the importance of great communication. Had to turn in a project that wasn’t running up to the standard I know I could have gotten it to because of poor team communication. Team comments and solid commit messages are crucial.

- There are many others but I saw theses as the most important two and I wanted to get these repos to you ASAP. 

---

## Note:
It is a pretty rusty project; we had some trouble as a group finding time for all of us to meet up and pair program so some of the components are janky and the sim has trouble running sometimes. Lessons learned though.

---
### How to Use:
    STEPS:
        1.)In main.cpp on line 20 input the time frame you want the sim to run for and
           the number of denizens you wish to have populating simville
                ->EX: Simulator.run_sim(10, 10) 
                ->run_sim(days, population)

        2.)Using the terminal tab build the project with your desired parameter for
           the sim, then using the same tab(terminal) press run and let the computer
           work.

        3.)To look at your simulation results, after the sim runs, click on the file
           Simulation_results.txt | In that file you will be able to see how your
           simulation played out.
