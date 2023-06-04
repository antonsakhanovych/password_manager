# Password Manager
## What is this project?
This project is part of my c++ first year course at the PJAIT university.
This course covers topics like pointers, references, operator overloading, inheritance, diamond problem, polymorphism.

## Compilation
```bash
# copy this github repository
git clone https://github.com/antonsakhanovych/password_manager.git

# cd into the directory
cd password_manager

# compile the program
make main

# start by running:
./build/main
```
	
There is a pass file available for you to test the program.

```bash
# to clean the build you can type
make clean
```

	
## Features

1. The file is encrypted using xor algorithm
2. You can add, delete, and edit passwords.
3. Passwords have name, password, category, service, and login fields.
4. Every time you do an action on the password file, program loads passwords from file, performs an action, and deletes the password objects. This is done to reduce the time of password information presence in the RAM.

## Authors
- Anton Sakhanovych
