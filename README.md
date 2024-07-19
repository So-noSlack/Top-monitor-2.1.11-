# Top monitor[2.1.11]

Brief description of project purpose: A system that assists teachers in statistical quantification.

[Description](https://www.cnblogs.com/So-noSlack/p/18310379)

# Top monitor item Description

The project is designed to help teachers manage student quantification procedures, the default has three ports, respectively for the student side, the teacher side and the management side. The copyright notice can be found on the main page.

The prominent function of the project is mainly divided into three ports, which can handle a number of operations respectively, and do not interfere with each other, and the functions of each port are also very powerful. It mainly highlights the word "practical", which has been put into use for one year in Class 2509 of Zhengzhou No.1 High School Experimental School, during which the code has been continuously optimized and upgraded to [2.1.11] version, and has been continuously improved and improved, updating multiple functions such as log, question, view total ranking and export quantization.

Main functions: log ---- The development of the log function is mainly developed to prevent students from maliciously modifying quantification. It can record the modified person, modified time, modified person, modified score, and so on. It can effectively prevent the occurrence of malicious modification quantification, and it plays a role many times during the use, which is very powerful.

**Strong security: You need to enter a private key to log in to the teacher or administrator account. There are 1000 private keys in this key group, and the key you need to enter is different for each login. Therefore, only the person who has this key group can log in to the teacher or administrator account. Without this key group, even if the account password is known, the login will not be successful.**


# Introduction of each end

The main functions of the student side - view the quantization score (oneself), view the ranking (oneself), modify the password (oneself), modify the quantization (only the section representative), ask the teacher about the quantization, exit the login.

The main function of the teacher side - modification quantification. View ranking (whole class), view change log, view account (student/teacher in case you forget password), register account (student/teacher), export data (export log or quantify ranking), view questions (only questions addressed to this teacher can be seen), log out.

The main functions of the management side - register the account (student/teacher/management), view the modification log, view the account (student/teacher/management), modify the account (student/teacher), view the ranking (class). Export data (logs and rankings) and log out.

This project not only helps teachers reduce the time of calculation and quantification, but also has a large space for development. It can gradually add more functions and optimize the operation page. Later, it will consider adding database support and changing to a web version for better operation.
The file storage in the project is stored in the.so_noslack document, and this has a drawback is that on different devices, the data will not be synchronized, and the further plan is to call the MySQL database in C++, and call the data storage with SQL statements so that it is convenient to interwork on different devices.


# Project implementation process

In this project, it is different from many projects that have been done before, including address book management system, employee management system, iPhone calendar, Chinese c++, video viewing system and other projects. Due to immature technology, this project wasted a lot of time, in the project implementation process, we also continue to learn, progress, to complete this project, learn the file operation, export Excel, multi-element sorting, set.exe page and so on.

Of course, there are many problems in the implementation process:
At first, in the login port and management side, I was not familiar with the operation of the file, resulting in abnormal data output, garbled codes, etc., and I did not know how to turn the.txt file into a.CVS chart. Of course, in the writing process, it was gradually improved, such as adding students can view their own quantitative ranking, teachers can view the ranking of all students, and adding export log files. Quantitative ranking, etc., the process is very bumpy, and finally after more than a week to complete the project.

Declaration: This system is developed by So-noSlack.


# Comparison of similar projects

Similar projects useful Javaweb development website, using the database system, but most of the functions are similar to this project, but one is a website, our one.exe file, but their data can be interoperable, our can only be stored on a computer, but our functions are more comprehensive, Quantization rankings can be exported as a table in the form of.cvs, as well as logging capabilities.
