package info.stepanoff.trsis.lab1.servlets;

import info.stepanoff.trsis.lab1.model.DataModel;
import info.stepanoff.trsis.lab1.model.Student;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(name = "ExampleServlet", urlPatterns = {"/students_list"})
public class ExampleServlet extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Student list</title>");
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Список студентов</h1>");

            List<Student> students = DataModel.getAllStudents();

            out.println("<table>");
            out.println("<thead>");
            out.println("<tr>");
            out.println("<th>ID</th>");
            out.println("<th>ФИО</th>");
            out.println("<th>Вариант задания</th>");
            out.println("<th>Число сданных лабораторных</th>");
            out.println("<th>Рейтинг</th>");
            out.println("</tr>");
            out.println("</thead>");
            out.println("<tbody>");
            for (Student student : students) {
                out.println("<tr>");
                out.println("<td>" + student.getId() + "</td>");
                out.println("<td>" + student.getFullName() + "</td>");
                out.println("<td>" + student.getAssignmentVariant() + "</td>");
                out.println("<td>" + student.getLabCount() + "</td>");
                out.println("<td>" + student.getRating() + "</td>");
                out.println("</tr>");
            }
            out.println("</tbody>");
            out.println("</table>");

            // Форма добавления студента
            out.println("<h2>Добавить студента</h2>");
            out.println("<form action=\"/add_student\" method=\"post\">");
            out.println("ФИО: <input type=\"text\" name=\"fullName\" required><br>");
            out.println("Вариант задания: <input type=\"number\" name=\"assignmentVariant\" required><br>");
            out.println("Число сданных лабораторных: <input type=\"number\" name=\"labCount\" required><br>");
            out.println("Рейтинг: <input type=\"number\" name=\"rating\" required><br>");
            out.println("<input type=\"submit\" value=\"Добавить\">");
            out.println("</form>");

            // Форма удаления студента
            out.println("<h2>Удалить студента</h2>");
            out.println("<form action=\"/delete_student\" method=\"post\">");
            out.println("ID студента: <input type=\"number\" name=\"studentId\" required><br>");
            out.println("<input type=\"submit\" value=\"Удалить\">");
            out.println("</form>");
            

            // Форма поиска студентов
            out.println("<h2>Поиск студента</h2>");
            out.println("<form action=\"/search_student\" method=\"post\">");
            out.println("Поиск по ФИО: <input type=\"text\" name=\"searchQuery\" required><br>");
            out.println("<input type=\"submit\" value=\"Поиск\">");
            out.println("</form>");

            out.println("</body>");
            out.println("</html>");
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }
}
