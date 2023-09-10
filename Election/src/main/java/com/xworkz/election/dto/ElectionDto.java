package com.xworkz.election.dto;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.NamedQuery;

import com.xworkz.test.Table;

import lombok.Data;

@Entity
@Table
@Data
@NamedQuery(name = "readAll", query = "select dto from ElectionDto dto")
public class ElectionDto {

	@Id
	private int id;
	private String name;
	private long phoneNumber;
	private int age;
	private String address;
	private int pincode;

	public ElectionDto(String name, long phoneNumber, int age, String address, int pincode) {
		super();
		this.name = name;
		this.phoneNumber = phoneNumber;
		this.age = age;
		this.address = address;
		this.pincode = pincode;
	}

}
