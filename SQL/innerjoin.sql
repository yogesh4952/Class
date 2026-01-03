create table orders(
	order_id serial,
	order_date date not null,
	price numeric not null,
	cust_id int not null,
	primary key(order_id),
	foreign key(cust_id) references
	customers(cust_id)
);

select * from orders;
select * from customers

insert into customers(cust_name)
values 
('Raju'),('Sham'),('Paul'),('Alex');

INSERT INTO orders (order_date, cust_id, price)
VALUES 
    ('2024-01-01', 1, 250.00),  
	('2024-01-15', 1, 300.00),  
	('2024-02-01', 2, 150.00),
	('2024-03-01', 3, 450.00),
	('2024-04-04', 2, 550.00);  


select * from customers c
inner join orders o
on c.cust_id = o.cust_id


-- Find how much order this customer placed
select c.cust_name , count(o.order_id) as total_orders
from customers c
inner join
orders o
	on o.cust_id = c.cust_id
	group by c.cust_name


-- Find total amount spent by each customer
EXPLAIN ANALYZE
select c.cust_name, sum(o.price) 
from customers c
inner join orders o
on o.cust_id = c.cust_id
group by c.cust_name

