CREATE DATABASE LAB5
USE LAB5

--no.1
DROP TABLE student
DROP TABLE studentlog
CREATE TABLE student(
sid int primary key,
sname varchar(30),
marks int,
saddress varchar(40)
)

CREATE TABLE studentlog(
logid int identity(1,1),
sid int ,
actiontype varchar(30),
actiontime date
foreign key(sid) references student(sid)
)

select * from student

--no.2 create a trigger studentlog trigger in which log of student table inserted automatically when new data inserted to student table
CREATE TRIGGER studentlog_trigger
ON student
AFTER INSERT
AS
BEGIN
    INSERT INTO studentlog (sid, actiontype, actiontime)
    SELECT sid, 'INSERT', GETDATE()
    FROM inserted;
END;

INSERT INTO student (sid, sname, marks, saddress)
VALUES (122, 'Abinash', 56, 'Bhaktapur');

SELECT * FROM studentlog;


--no.3 create a trigger 'student_message'after inserting dates to student table
CREATE TRIGGER student_message
ON student
AFTER INSERT
AS
BEGIN
    PRINT 'New student record has been inserted into the student table.';
END;


--no.4
CREATE TRIGGER student_totalmarks
ON student
AFTER INSERT
AS
BEGIN
    DECLARE @total DECIMAL(10,2);

    SELECT @total = SUM(marks)
    FROM student;

    PRINT 'Total marks of all students: ' + CAST(@total AS VARCHAR(20));
END;

INSERT INTO student (sid, sname, marks, saddress)
VALUES (10, 'Ram', 85.50, 'Kathmandu');











