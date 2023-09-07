package main.java.com.xworkz.airpods.repo;

import java.util.List;

import main.java.com.xworkz.airpods.dto.AirpodsDto;

public interface AirpodsRepo {
	
	public boolean store(AirpodsDto dto1);

	public boolean updateColorByName(String color, String name);

	public boolean deleteByPrice(int price);

	public List<AirpodsDto> readAll();
	
}
