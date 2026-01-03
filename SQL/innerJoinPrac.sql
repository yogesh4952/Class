create table recipe_classes(
	recipe_class_id serial primary key,
	recipe_class_desc varchar(50) not null
);


create table recipe(
	recipeId serial primary key,
	recipeTitle varchar(20) not null,
	recipeClassId int not null,
	preparation varchar(20),
	notes varchar(50),
	foreign key (recipeClassId) references recipe_classes(recipe_class_id)
)

alter table recipe
 add constraint recipe_recipeclassid_fkey
 foreign key (recipeClassId)
 references recipe_classes(recipe_class_id)
 on update cascade
 on delete cascade;



 -- Insert into recipe_classes
INSERT INTO recipe_class_desc  (recipe_class_desc) 
VALUES
('Breakfast'),
('Lunch'),
('Dinner'),
('Dessert'),
('Snack');

-- Insert into recipe
INSERT INTO recipe (recipeTitle, recipeClassId, preparation, notes)
VALUES
('Pancakes', 1, '15 mins', 'Serve with syrup'),
('Grilled Cheese', 2, '10 mins', 'Best with cheddar'),
('Spaghetti Bolognese', 3, '30 mins', 'Add parmesan on top'),
('Chocolate Cake', 4, '1 hour', 'Use dark chocolate for rich flavor'),
('Fruit Salad', 5, '10 mins', 'Mix seasonal fruits'),
('Omelette', 1, '8 mins', 'Add veggies for nutrition'),
('Burger', 2, '20 mins', 'Toast the buns first'),
('Steak', 3, '25 mins', 'Cook medium rare'),
('Ice Cream Sundae', 4, '5 mins', 'Top with nuts and syrup'),
('Nachos', 5, '15 mins', 'Great with salsa and cheese');




select r.recipeTitle,r.preparation,rc.recipe_class_desc
from recipe_classes rc
inner join recipe r
on r.recipeClassId  = rc.recipe_class_id 
group by r.recipeTitle,r.preparation,rc.recipe_class_desc

 


select * from recipe

select * from recipe_classes

