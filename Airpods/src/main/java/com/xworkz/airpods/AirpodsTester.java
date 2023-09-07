package main.java.com.xworkz.airpods;

import java.util.List;

import main.java.com.xworkz.airpods.dto.AirpodsDto;
import main.java.com.xworkz.airpods.service.AirpodsService;
import main.java.com.xworkz.airpods.service.AirpodsServiceImpl;

public class AirpodsTester {

	public static void main(String[] args) {

		AirpodsService service = new AirpodsServiceImpl();
		AirpodsDto dto = new AirpodsDto(3, "OnePlus", 5000, "white", 15);

		// service.store(dto);
		System.out.println(dto);
		// service.updateColorByName("black", "OnePlus");

		// service.deleteByPrice(5000);
		List<AirpodsDto> list = service.readAll();
		System.out.println(list);
	}

}
