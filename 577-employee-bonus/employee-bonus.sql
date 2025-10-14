# Write your MySQL query statement below

select e1.name, b2.bonus 
from Employee e1 left outer join Bonus b2
on e1.empId = b2.empId where b2.bonus < 1000 or b2.bonus is NULL;

