package com.xworkz.election.service;

import java.util.List;

import com.xworkz.election.dto.ElectionDto;


public interface ElectionService {
	

	public boolean save(ElectionDto dto);

	public List<ElectionDto> readAll();

}
