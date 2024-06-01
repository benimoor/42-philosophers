# 42-philosophers

42-philosophers is a project developed as part of the 42 École curriculum, which involves solving the dining philosophers problem using multithreading concepts in C.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Problem Description](#problem-description)
- [Solution](#solution)
- [Contact](#contact)

## Introduction

42-philosophers is an exercise in concurrent programming and synchronization. It simulates the dining philosophers problem, where a number of philosophers sit around a dining table with a bowl of spaghetti in front of each. There are forks between each pair of adjacent philosophers, and a philosopher needs two forks to eat.

## Features

- Multithreaded implementation using pthreads.
- Synchronization mechanisms (mutexes or semaphores) to prevent deadlocks and race conditions.
- Visualization of philosopher actions (if implemented).

## Installation

To build and run the philosophers project, follow these steps:

1. **Clone the repository**
   ```
   git clone https://github.com/your_username/philosophers.git
   cd philosophers

    Build the project

    make

## Usage

To start the philosophers simulation, run the compiled executable with the desired number of philosophers, time to die, time to eat, time to sleep, and optionally the number of times each philosopher must eat:

    ./philosophers num_philosophers time_to_die time_to_eat time_to_sleep [num_times_to_eat]

## Problem Description

The dining philosophers problem involves a finite set of philosophers who sit at a round table and do the following repeatedly:

    Think: Philosophers spend time thinking.
    Grab forks: A philosopher must pick up the two forks adjacent to them to eat.
    Eat: Once a philosopher has both forks, they eat for a certain amount of time.
    Release forks: After eating, a philosopher puts down both forks and returns to thinking.

The challenge is to ensure that no two neighboring philosophers eat simultaneously, to prevent deadlock.

## Solution

The philosophers project implements a solution using multithreading concepts, where each philosopher is represented by a thread. Synchronization mechanisms like mutexes or semaphores are used to prevent deadlocks and race conditions when accessing shared resources like forks.

## Contact

Erik Grigoryan - ergrigor@student.42yerevan.am
