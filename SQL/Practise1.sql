select * from employee2;
insert into employee2(name,dept,salary,gender,hireyear)
values
('Ravi','IT', 40000, 'M' , '2019-3-12'),('Sita','IT', 50000, 'F','2020-4-12'), ('Gopal','HR',35000 ,'M','2017-5-12'), ('Anil' ,'Finance' , 60000, 'M','2019-6-1'),('Laxmi' ,'Finance' ,55000 ,'F','2020-7-12'),('Tara','IT', 45000, 'F','2018-12-1');



-- To select the total number of employee in each department

select count(*) from employee2
group by dept;

-- Find the average salary of each department

select avg(salary),dept from employee2
group by dept


-- Unique department
select distinct dept from employee2


-- Highest salary in each department
select max(salary), dept from employee2
group by dept


-- Find number of male and female in each department
select  gender ,dept, count(*) as total from employee2
group by dept ,gender
order by dept 

-- For each hireyear find total salary
select sum(salary),hireyear from employee2
group by hireyear




-- Practice for employee database
select * from employee

-- Find different type of departments in databse

select distinct  dept from employee

-- Display records with high-low salary
select * from employee
order by salary desc


-- How to see only top 3 records from a table
select * from employee
limit 3

-- Show record where first name start with letter 'A'
SELECT * FROM employee
where fname like 'A%'


-- Show record where length of the lname is 4 character
select * from employee 
where lname like '____'
