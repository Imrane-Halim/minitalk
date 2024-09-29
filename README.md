# Minitalk 📱💻
================

A small data exchange program using UNIX signals 📡

## Table of Contents
-----------------

* [Introduction](#introduction)
* [Features](#features)
* [Usage](#usage)
* [Compilation](#compilation)

## Introduction
------------

Minitalk is a communication program that uses UNIX signals to exchange data between a client and a server. The program consists of two parts: a server that receives messages and a client that sends messages.

## Features
------------

* 📝 **Mandatory Part**: The server prints its PID after launch, and the client sends a string to the server using UNIX signals.
* 📝 **Bonus Part**: The server acknowledges every message received by sending back a signal to the client, and supports Unicode characters.

## Usage
-----

### Server

1. Compile the server using `make`.
2. Run the server using `./server`.
3. The server will print its PID.

### Client

1. Compile the client using `make`.
2. Run the client using `./client <server_pid> <message>`.
3. The client will send the message to the server.

## Compilation
------------

To compile the program, use the following command:
```bash
make
