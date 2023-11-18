# MSKN Installation

Hello, welcome to our Command Simplify scenario with MSKN. Today, we will examine the MSKN program, which is a program created to facilitate the commands we use in the terminal in our Pardus operating system.

### 1. Clone Project to Your Environment

First, clone the project to your own environment using the token with the "git clone" command:

```sh
git clone https://<username>:<git_user_token>@github.com/MertGursimsir/mskn.git
```

Then go to the project directory:

```sh
cd mskn
```

### 2. Install the Requirements

"gcc" (GNU Compiler Collection) will be used to compile the C code in the project. Therefore, install the "gcc" compiler on your system with the following command:

```sh
sudo apt-get install gcc
```

### 3. Compile and Run the Code

Use the following command for the compilation process:

```sh
gcc history.c -o history
```

Then run the compiled file with the following command:

```sh
./history
```

### 4. Additional Installations

If you get a compilation error, execute the following commands and go back to step 3:

```sh
sudo apt-get update
sudo apt-get install build-essential
```

If you still don't get results, enter the following command:

```sh
sudo apt-get install libc6-dev
```