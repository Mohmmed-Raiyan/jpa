# jpa


CREATE DATABASE Employees;
USE Employees;

CREATE TABLE employees (
    employee_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    department_id INT,
    salary DECIMAL(10, 2)
);

CREATE TABLE department (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(100)
);

INSERT INTO department (department_id, department_name) VALUES
(1, 'Human Resources'),
(2, 'Finance'),
(3, 'Engineering'),
(4, 'Marketing');

INSERT INTO employees (first_name, last_name, department_id, salary) VALUES
('John', 'Doe', 1, 5000),
('Jane', 'Smith', 2, 7000),
('Sam', 'Williams', 3, 10000),
('Sue', 'Jones', 3, 12000),
('Anna', 'Brown', 4, 3000),
('Tom', 'Davis', 4, 15000);

select * from employees;
select * from department;

Delimiter //
create procedure my_proc_min_Sal()
begin
select MIN(salary) From employees
group by department_id;
end//
Delimiter ;
Call my_proc_min_Sal();

Delimiter //
Create Procedure my_proc_Max_Sal()
BEGIN
      SELECT MAX(salary)FROM employees  
      GROUP BY department_id;
END//
Delimiter ;
Call my_proc_Max_Sal ();

Delimiter //
create procedure my_proc_Avg_Sal()
begin
	select AVG(salary) from employees
    group by department_id;
end//
Delimiter ;
call my_proc_Avg_Sal();

Delimiter //
create procedure my_proc_Morethan_AVG_Sal()
begin 
	select first_name,last_name,salary,department_id
    from employees
where salary > (select AVG(salary) from employees)
    order by salary desc;
    end//
delimiter ;
call my_proc_Morethan_AVG_Sal();

DELIMITER //
Create Procedure my_proc_emp_dept_details1()
BEGIN
SELECT e.first_name, e.last_name , e.department_id ,d.department_name
  FROM employees e
  JOIN department d 
    ON e.department_id=d.department_id;
END//
Delimiter ;
call my_proc_emp_dept_details1();

delimiter //
create procedure empl_info(IN empl_id integer)
begin
select employee_id, first_name,last_name from employees
where salary > (select salary from employees where
employee_id=empl_id);
end //
delimiter ;
call empl_info(2);

Delimiter //
create procedure empl_info_out(OUT Emp Int)
begin
select count(*) into Emp
from department join employees using(department_id)
where Salary>=10000;
end//
delimiter ;
call empl_info_Out(@Emp_count);
select @Emp_count as Employee_Sal;

DELIMITER //
Create Procedure empl_info_InOut(INOUT Emp_Sal integer ,IN empl_id integer)
BEGIN
SELECT count(employee_id)into Emp_Sal
FROM employees 
WHERE salary > 
(SELECT salary  
     FROM employees 
       WHERE employee_id= empl_id);
END//
DELIMITER ;
CALL empl_info_InOut(@Emp_Sal,1);
Select @Emp_Sal as No_of_Emp;

show create procedure empl_info_Out;

show procedure status where name like '%Emp%';

DROP PROCEDURE IF EXISTS my_proc_Morethan_AVG_Sal;

drop database employees;
