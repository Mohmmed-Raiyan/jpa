package main.java.com.xworkz.airpods.service;

import java.util.List;

import main.java.com.xworkz.airpods.dto.AirpodsDto;

public interface AirpodsService {
	
	public boolean store(AirpodsDto dto);
	
	public List<AirpodsDto> readAll();
	
	public boolean updateColorByName(String color , String name);
	
	public boolean deleteByPrice(int price);


}
