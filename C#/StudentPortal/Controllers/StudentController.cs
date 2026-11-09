using Microsoft.AspNetCore.Mvc;
using StudentPortal.Models;
namespace StudentPortal.Controllers;

public class StudentController : Controller
{
    public IActionResult Index()
    {
        var student = new List<Student>
        {
            new Student{Id=1, Marks=230,Name="Kale"},
            new Student{Id=2, Marks=220,Name="Randi"},
            new Student{Id=3, Marks=250,Name="Khate"}
        };
        return View(student);
    }
    public IActionResult Details(int id)
    {
        var students = new List<Student>
    {
        new Student { Id = 1, Name = "Ram", Marks = 75 },
        new Student { Id = 2, Name = "Sita", Marks = 85 },
        new Student { Id = 3, Name = "Hari", Marks = 30 }
    };

        var student = students.FirstOrDefault(s => s.Id == id);

        if (student == null)
            return NotFound();

        return View(student);
    }

}