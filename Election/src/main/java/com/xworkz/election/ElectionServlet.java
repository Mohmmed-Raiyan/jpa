package com.xworkz.election;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.xworkz.election.dto.ElectionDto;
import com.xworkz.election.service.ElectionService;
import com.xworkz.election.service.ElectionServiceImpl;

@WebServlet(name = "/save")
public class ElectionServlet extends HttpServlet {

	ElectionService service = new ElectionServiceImpl();

	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String name = request.getParameter("name");
		long phoneNumber = Long.parseLong(request.getParameter("phoneNumber"));
		int age = Integer.parseInt(request.getParameter("age"));
		String address = request.getParameter("address");
		int pincode = Integer.parseInt(request.getParameter("pincode"));

		ElectionDto dto = new ElectionDto(name, phoneNumber, age, address, pincode);

		boolean status = service.save(dto);

		if (status) {
			request.getRequestDispatcher("/Read.jsp").forward(request, response);
		} else {
			response.setContentType("text/html");
			PrintWriter writer = response.getWriter();
			writer.print("Data not valid so not saved");
			request.getRequestDispatcher("/ElectionForm.jsp").include(request, response);
		}

	}

}
