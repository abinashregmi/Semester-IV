CREATE DATABASE constraintlab4
CREATE TABLE department(
did int primary key,
dname varchar(20) NOT NULL,
location varchar(20) default 'head office'
)
CREATE TABLE employee(
eid int identity(1,1) primary key,
fname varchar(20) NOT NULL,
mname varchar(20),
lname varchar(20) NOT NULL,
Email varchar(20) unique,
salary decimal(10,2) check(salary >= 18000),
did int , foreign key(did) references department(did),
joindate date default getdate()
)
select*
from department

select *
from employee

INSERT INTO department (did, dname, location) VALUES
(1, 'Human Resources', 'Kathmandu'),
(2, 'Finance', 'Pokhara'),
(3, 'IT', 'Lalitpur'),
(4, 'Marketing', 'Biratnagar'),
(5, 'Sales', 'Butwal'),
(6, 'Operations', 'Dharan'),
(7, 'Legal', 'Bhaktapur'),
(8, 'Research', 'Janakpur'),
(9, 'Customer Service', 'Nepalgunj'),
(10, 'Administration', 'head office');

INSERT INTO employee (fname, mname, lname, Email, salary, did, joindate) VALUES
('Rajan', 'Kumar', 'Joshi', 'rajan.joshi@ex.com', 24000.00, 1, '2024-05-10'),
('Sneha', NULL, 'Tamang', 'sneha.tamang@ex.com', 22000.00, 2, '2023-10-01'),
('Bibek', 'Prasad', 'Shah', 'bibek.shah@ex.com', 26000.00, 3, '2022-08-15'),
('Laxmi', NULL, 'Malla', 'laxmi.malla@ex.com', 20000.00, 4, '2025-02-20'),
('Kamal', 'Raj', 'Thapa', 'kamal.thapa@ex.com', 23000.00, 3, '2023-06-30'),
('Nabin', NULL, 'Rai', 'nabin.rai123@ex.com', 21000.00, 6, '2024-07-12'),
('Pooja', 'Devi', 'Shrestha', 'pooja.shres@ex.com', 25000.00, 1, '2022-11-05'),
('Suman', NULL, 'Lama', 'suman.lama12@ex.com', 19500.00, 8, '2023-03-18'),
('Asha', 'Kumari', 'Yadav', 'asha.yadav12@ex.com', 21500.00, 9, '2024-09-25'),
('Manoj', NULL, 'Karki', 'manoj.karki@ex.com', 27000.00, 2, '2025-01-01');

INSERT INTO employee(fname, mname, lname, Email, salary, did)
VALUES('uncle','kumar','jha','adsss@gmail.com',15000,1)

INSERT INTO employee(fname, mname, lname, Email, salary, did)
VALUES('abd','kumar','jha','abd@gmail.com',150000,1),
('bad','kumar','jha','abd@gmail.com',150000,1)



DELETE from department
WHERE dname = 'IT'

SELECT *
from employee e
LEFT JOIN department d
ON e.did = d.did
WHERE d.did IS NULL;