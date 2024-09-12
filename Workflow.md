# Synchronizing Class Server Files with Local Windows Directory Using WSL

## Table of Contents

- [Synchronizing Class Server Files with Local Windows Directory Using WSL](#synchronizing-class-server-files-with-local-windows-directory-using-wsl)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Prerequisites](#prerequisites)
  - [Directory Structure](#directory-structure)
  - [Step-by-Step Guide](#step-by-step-guide)
    - [1. Open Ubuntu WSL Terminal](#1-open-ubuntu-wsl-terminal)
    - [2. Navigate to Your Local Windows Directory in WSL](#2-navigate-to-your-local-windows-directory-in-wsl)
    - [3. Create the Local Directory](#3-create-the-local-directory)
    - [4. Copy Files from Class Server to Local Directory](#4-copy-files-from-class-server-to-local-directory)
    - [5. Verify the Files are Copied Locally](#5-verify-the-files-are-copied-locally)
    - [6. Edit the Files Locally](#6-edit-the-files-locally)
    - [7. Copy Files Back to the Class Server](#7-copy-files-back-to-the-class-server)
    - [8. Verify the Files are Updated on the Class Server](#8-verify-the-files-are-updated-on-the-class-server)
  - [Troubleshooting](#troubleshooting)
  - [Tips](#tips)

---

## Overview

This guide provides a step-by-step process to copy files between your class server and your local Windows directory using Ubuntu WSL (Windows Subsystem for Linux). You'll learn how to:

- Copy files from the class server to your local Windows directory.
- Edit the files locally using your preferred code editor.
- Copy the edited files back to the class server.

---

## Prerequisites

- **Operating System**: Windows 11 Pro
- **Terminal**: Windows Terminal with Ubuntu WSL installed
- **Code Editor**: Cursor/VS Code Fork or any preferred code editor
- **Class Server Access**: SSH access to the class server
- **Tools Installed**:
  - `ssh`
  - `scp`

---

## Directory Structure

- **Class Server Directory**: `~/labs/` (on the class server)
  - This directory contains weekly lab folders: `lab01`, `lab02`, `lab03`, etc.
  - New labs are added each week using the `gimmie` command
    ~/labs/
    ├── lab01/
    │ ├── file1.cpp
    │ └── file2.h
    ├── lab02/
    │ ├── assignment1.cpp
    │ └── assignment2.h
    ├── lab03/
    │ ├── project.cpp
    │ └── header.h
    ├── lab04/
    │ ├── exercise1.cpp
    │ └── exercise2.h
    └── ... (future labs)
- **Local Windows Directory**: `C:\Users\Owner\Documents\Github_Repositories\CSCI-41`
  - This is where you'll create local copies of each lab folder
    C:\Users\Owner\Documents\Github_Repositories\CSCI-41\
    ├── lab01\
    │ ├── file1.cpp
    │ └── file2.h
    ├── lab02\
    │ ├── assignment1.cpp
    │ └── assignment2.h
    ├── lab03\
    │ ├── project.cpp
    │ └── header.h
    ├── lab04\
    │ ├── exercise1.cpp
    │ └── exercise2.h
    └── ... (future labs)

---

## Step-by-Step Guide

### 1. Open Ubuntu WSL Terminal

Launch the **Ubuntu WSL** terminal using **Windows Terminal**.

### 2. Navigate to Your Local Windows Directory in WSL

In the terminal, navigate to your local Windows directory using the `/mnt/` mount point:

```bash
cd /mnt/c/Users/Owner/Documents/Github_Repositories/CSCI-41/
```

### 3. Create the Local Directory

Ensure that the `lab4` directory exists locally. If not, create it:

```bash
mkdir -p lab4
```

### 4. Copy Files from Class Server to Local Directory

Use `scp` to securely copy the contents of the `lab04` directory from the class server to your local `lab4` directory:

```bash
scp -r 'spraggins_0524626@5.75.133.4:~/labs/lab04/' ./lab4/
```

- The `-r` flag enables recursive copying for directories.

**Explanation:**

- **Source**: `spraggins_0524626@5.75.133.4:~/labs/lab04/*` (all contents of `lab04` on the class server)
- **Destination**: `./lab4/` (your local `lab4` directory)

### 5. Verify the Files are Copied Locally

List the contents of the `lab4` directory to ensure the files are copied:

```bash
ls -l lab4
```

### 6. Edit the Files Locally

Open your code editor and edit the files in:

```
C:\Users\Owner\Documents\Github_Repositories\CSCI-41\lab4
```

### 7. Copy Files Back to the Class Server

After editing, use `scp` to copy the files back to the class server's `lab04` directory:

```bash
scp -r ./lab4/ 'spraggins_0524626@5.75.133.4:~/labs/lab04/'
```

**Explanation:**

- **Source**: `./lab4/*` (all contents of your local `lab4` directory)
- **Destination**: `spraggins_0524626@5.75.133.4:~/labs/lab04/` (the `lab04` directory on the class server)

### 8. Verify the Files are Updated on the Class Server

SSH into the class server and check the `lab04` directory:

```bash
ssh spraggins_0524626@5.75.133.4
cd ~/labs/lab04
ls -l
```

Ensure that your changes are reflected on the server.

---

## Troubleshooting

- **Permission Denied Errors**: Ensure you have the correct permissions on both your local machine and the class server.
- **SSH Authentication Issues**: If prompted for a password, ensure your SSH credentials are correct. Consider setting up SSH keys for passwordless authentication.
- **File Overwrite Confirmation**: The `scp` command with the `-r` flag will overwrite existing files without prompting. Ensure this is acceptable before proceeding.

---

## Tips

- **Automate with Scripts**: Create shell scripts for copying files to and from the class server to streamline your workflow.
- **Use Version Control**: If permitted, use Git to manage your code versions and simplify synchronization between environments.
- **Consistent Directory Names**: Keep directory names consistent between your local and server environments to avoid confusion.
