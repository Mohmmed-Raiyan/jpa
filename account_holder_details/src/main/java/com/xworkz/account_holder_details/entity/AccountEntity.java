package com.xworkz.account_holder_details.entity;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;

import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@Entity
@Table(name="accountentity")
@NoArgsConstructor
@NamedQueries({@NamedQuery(name="searchAll",query="select e from AccountEntity e" ),
			  })

public class AccountEntity implements Serializable{

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private int id;
	@Column(name="t_firstName")
	
	private String firstName;
	
	@Column(name="t_lastName")
	private String lastName;
	
	@Column(name="t_email")
	private String email;
	
	@Column(name="t_contact")
	private long contact;
	
	@Column(name="t_dateOfBirth")
	private String dateOfBirth;
	
	@Column(name="t_annualIncome")
	private long annualIncome;
	
	@Column(name="t_address")
	private String address;
	
	@Column(name="t_qualification")
	private String qualification;
	
	@Column(name="t_bloodGroup")
	private String bloodGroup;
	
	@Column(name="t_accountNumber")
	private long accountNumber;
	
	@Column(name="t_accountType")
	private String accountType;
	
	@Column(name="t_onlineBanking")
	private boolean onlineBanking;
	
	public AccountEntity( String firstName, String lastName, String email, long contact, String dateOfBirth,
			long annualIncome, String address, String qualification, String bloodGroup, long accountNumber,
			String accountType, boolean onlineBanking) {
		
		this.firstName = firstName;
		this.lastName = lastName;
		this.email = email;
		this.contact = contact;
		this.dateOfBirth = dateOfBirth;
		this.annualIncome = annualIncome;
		this.address = address;
		this.qualification = qualification;
		this.bloodGroup = bloodGroup;
		this.accountNumber = accountNumber;
		this.accountType = accountType;
		this.onlineBanking = onlineBanking;
	}
	
}
