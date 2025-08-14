

CREATE DATABASE LAB3
create table student(
sid int identity(1,1) primary key,
sname varchar(20) NOT NULL,
saddress varchar(20),
DOB DATE,
Marks float
);
COMMIT
ROLLBACK
Select * from Student;
INSERT INTO student (sname, saddress, DOB, Marks) VALUES
('Aarav Sharma', 'Kathmandu', '2005-03-15', 85.5),
('Sita Thapa', 'Lalitpur', '2004-07-22', 78.0),
('Ramesh Karki', 'Bhaktapur', '2005-11-05', 92.3),
('Anjali Rai', 'Pokhara', '2006-01-30', 88.7),
('Bikash Gurung', 'Biratnagar', '2004-09-12', 74.5),
('Nisha Shrestha', 'Dharan', '2005-06-18', 81.2),
('Prakash Lama', 'Butwal', '2006-04-25', 69.8),
('Meena Raut', 'Besisahar', '2004-11-11', 89.4),
('Bibek Regmi', 'Jumla', '2006-01-05', 77.8),
('Laxmi Bhandari', 'Ilam', '2005-08-19', 86.6);


select *
from student;

COMMIT

ROLLBACK 

DELETE FROM student WHERE saddress = 'kathmandu';

UPDATE student
SET saddress = 'Bhaktapur'
WHERE Marks > 80

DROP TABLE student;