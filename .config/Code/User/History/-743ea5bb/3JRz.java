package com.practice;

import javax.persistence.Entity;
import javax.persistence.Id;

@Entity
public class Student{
    
    @Id
    private int rollNo;

    private String name;
    private double gpa;

    public Student(){
        
    }

    public Student(int rollNo, String name, double gpa){
        this.rollNo = rollNo;
        this.name = name;
        this.gpa = gpa;
    }

    public int getRollNo(){
        return rollNo;
    }
    public void setRollNo(int rollNo){
        this.rollNo = rollNo;
    }
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }
    public double getGPA(){
        return gpa;
    }
    public void setGPA(double gpa){
        this.gpa = gpa;
    }

}
