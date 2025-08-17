-- Find the employee which salary is more than the average salary


This is wrong because we cannot use aggreagte function in where clause
select * from employee
where salary>avg(salary)


-- Here we use subquery to do this
select * from employee
where salary > (select avg(salary) from employee)