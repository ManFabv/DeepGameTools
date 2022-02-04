# Installing SonarQube in Ubuntu Server 20.04 - Part 1 - Prerequisites

## Disclaimer
This is not intended to be a comprensive guide and the idea is to take a more practical approach on how we can install and have a basic setup for SonarQube, with that in mind I apologize for not going too deep.

**Note**
This tutorial assumes that you have an Ubuntu Server 20.04.3 instance running (in a local machine or through some cloud service will work).
For almost all the steps we need to do, we are going to use the terminal, so a basic knowledge of some commands are needed but I'm going to try to explain each command that we use.
**If you see any mistake or something that it's worth explaining a little more, feel free to let me know. Thanks!**

## What is SonarQube
SonarQube is an open source software for monitoring the software quality we are developing.
SonarQube maintains an historical record of several kinds of data and code quality metrics that we can use to take decisions about which areas of our software we need to improve. This data allows developer's teams to manage and follow up the quality of the software through different data and metrics that point key areas for improvements and prevents developers to make some common mistakes which in turn, free developers to focus only on other things related to the development process.

## Tools that we can use with SonarQube
SonarQube has the ability to be configured through different plugins which extends its capabilities and gives us the oportunity to integrate it with some really well known tools, such as **PVS-Studio, CPPCheck, StyleCop**, and so on.
You can see a list of available plugins in the following url: [SonarQube Marketplace](https://docs3.sonarqube.org/latest/instance-administration/marketplace/)
It's worth noting that in that url we can't find every plugin available. We have also available (among others, because some plugins are in their developer's website) some plugins developed by the community in this repository: [SonarQube Community Github](https://github.com/SonarQubeCommunity).
We have at our disposal support for several languages such as java, .net and many more. That means that we can, por example, scan our C# project for finding bugs or vulnerabilities and see those reports in the comprensive SonarQube web client

## Different Versions/Editions of SonarQube
SonarQube has different versions of the software that we can choose according to our needs.
One of those versions and the one we are going to install here is the **Community Edition**
This is a free edition for all users, but be careful because it comes with some limitations, for example:
* Less supported languages (for example it doesn't support C++)
* We can't scan our Pull Requests when they are made

If you want, you can see the full version's comparison in its official website
[SonarQube official site](https://www.sonarqube.org/)

## Prerequisites:
In order to get SonarQube up and running we need some prerequisites that we need to have installed, we are going to cover each one.

* OpenJDK 11
* PostgreSQL
* Setup PostgreSQL users and databases
* Setup Firewall
* PGAdmin (optional)

## Update the System
First of all, I like to have everything up to date, so, first we run the following command to update everything and clean up our Ubuntu System
```
sudo apt-get dist-upgrade -y && sudo apt-get update -y && sudo apt-get upgrade -y && sudo apt-get autoremove -y && sudo apt-get remove -y && sudo apt-get clean -y && sudo apt-get autoclean -y && sudo snap refresh
```

## Installing OpenJDK 11
```
sudo apt-get install openjdk-11-jdk -y
```
Now we can check if we have the correct version installed running this command
```
java -version
```
And we should see something like:

`openjdk version "11.0.13" 2021-10-19`

`OpenJDK Runtime Environment (build 11.0.13+8-Ubuntu-0ubuntu1.20.04)`

`OpenJDK 64-Bit Server VM (build 11.0.13+8-Ubuntu-0ubuntu1.20.04, mixed mode, sharing)`

## Installing PostgreSQL
We are going to setup the PostgreSQL repository to be able to install newer versions of the DataBase in our system
We add the repository through this command
```
sudo sh -c 'echo "deb http://apt.postgresql.org/pub/repos/apt/ `lsb_release -cs`-pgdg main" >> /etc/apt/sources.list.d/pgdg.list'
```
We then need to add the sign in key to the repository
```
wget -q https://www.postgresql.org/media/keys/ACCC4CF8.asc -O - | sudo apt-key add -
```
With these done, we need to update our repositories running:
```
sudo apt-get update -y
```
We have everything ready to do the installation with:
```
sudo apt-get install postgresql postgresql-contrib -y
```
After the installation finishes, we have now a new user created called `postgres`
We need to set the password for this user because we are going to use it for create databases and new users for PostgreSQL
```
sudo passwd postgres
```
We are going to be prompted to enter the sudo password and then the password for the postgres user.
We can now take a time to create our Ubuntu user that is going to run SonarQube
```
sudo useradd sonar
```
We need to set the password and some minimum data and after that we are ready to continue with PostgreSQL

Now we have to change to `postgres` user to be able to interact with PostgreSQL
```
su - postgres
```
Now we can start to create users for PostgreSQL through the command:
```
createuser sonar
```
With the users created, we can now enter the PostgreSQL command line
```
psql
```
We will be prompted with:
```
postgres=#
```
In the command prompt, we set the users passwords
First for the `postgres` user
```
ALTER USER postgres WITH ENCRYPTED password 'my_password';
```
And then for the `sonar` user
```
ALTER USER sonar WITH ENCRYPTED password 'my_password';
```
Now we have to create the data base for SonarQube, we use the following command:
```
CREATE DATABASE sonarqube OWNER sonar;
```
Then, we need to grant access to `sonarqube` data base to the user `sonar`
```
GRANT ALL PRIVILEGES ON DATABASE sonarqube to sonar;
```
Finally we exit the PostgreSQL command prompt
```
\q
```
And then leave `postgres` user and return to your user session
```
exit
```

## Setup Firewall
By default we don't have the firewall enabled, so, to do that, we need to run this command:
sudo ufw enable

After that we can add some rules to open the needed ports for pgAdmin and SonarQube following this commands
```
sudo ufw allow http
```
Now for Secure HTTP
```
sudo ufw allow https
```
And then the SonarQube default port
```
sudo ufw allow 9000/tcp comment "SonarQube port"
```
Finally we reload the firewall with:
```
sudo ufw reload
```

## Install pgAdmin as a web frontend for PostgreSQL (optional)
To have a more user friendly GUI for interact with PostgreSQL we are going to install pgAdmin
The steps are very similar to the ones we did for installing PostgreSQL and are as follows

We add the repository through this command
```
sudo sh -c 'echo "deb https://ftp.postgresql.org/pub/pgadmin/pgadmin4/apt/focal pgadmin4 main" > /etc/apt/sources.list.d/pgadmin4.list'
```
We then need to add the sign in key to the repository
```
wget -q https://www.pgadmin.org/static/packages_pgadmin_org.pub -O - | sudo apt-key add -
```
With these done, we need to update our repositories running:
```
sudo apt-get update -y
```
We have everything ready to do the installation with:
```
sudo apt-get install pgadmin4 -y
```
With pgAdmin installed, we proceed to the configuration of the web client
```
sudo /usr/pgadmin4/bin/setup-web.sh
```
You will be prompted for enter your email and password **NOTE:** don't forget this data because you are going to need it to login to pgadmin web page. Then you also are prompted that pgAdmin can configure Apache for us, we say yes.

After that, we are prompted to restart Apache, we also say yes and w can open the following url to access pgAdmin
```
http://127.0.0.1/pgadmin4
```

## Add a server to pgAdmin (optional)
If we decided to install pgAdmin, we also need to add a server to our pgAdmin installation, for doing this, we need to go to pgAdmin web page and login using our mail and password set when we run `setup-web.sh` command

* After login in you will see the `Dashboard` screen and one of the options is `Add Server`, we click on that button
* In the next popup that we see, in the `General` tab, we have to enter a server name, you can name it whatever you want, in this example we are going to name it `main-build-server`
* Now in the `Connection` tab we put the following values
    * hostname: localhost 
    * username: postgres
    * password: pass you set for postgres user (The one set with: *ALTER USER postgres ...*)
* Click on save and you're done

## Download SonarQube
The last step in this first part of the tutorial is going to be, download the actual SonarQube package for our Ubuntu system
In the Terminal download the file with this command:
```
wget https://binaries.sonarsource.com/Distribution/sonarqube/sonarqube-9.3.0.51899.zip
```

Keep this file because in the next post we are going to install SonarQube. See you in **Part 2**!