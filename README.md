# shell.c

Simple shell written in C. 

Tanzeem Nazmee
* RUID: 226001687
* NetID: tmn98

[GNU C manual used as reference.](https://www.gnu.org/software/libc/manual/html_node/Accessing-Directories.html)

## Usage

```
make all
./shell
```

Then type one of the following commands, followed by an argument if required.

## Commands

### cd
Change directory.

```
cd <directory>
```

### pwd
Print working directory.

```
pwd
```

### exit
Exit the shell.

```
exit
```

### help
Display help.

```
help
```

### mkdir
Create directory with path <DIRECTORY>.

```
mkdir <directory>
```

### rmdir
Remove empty directory with path <DIRECTORY>.

```
rmdir <directory>
```

### ls
List files in a directory <DIRECTORY>, or the current directory if no argument is supplied.

```
ls <directory>
```

### cp
Copy a file <SOURCE> to <DESTINATION>.

```
cp <source> <destination>
```

### mv
Move a file <SOURCE> to new path <DESTINATION>.

```
mv <source> <destination>
```

### rm
Remove a file <FILE>.

```
rm <file>
```
