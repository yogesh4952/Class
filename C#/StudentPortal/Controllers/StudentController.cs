using Microsoft.AspNetCore.Mvc;
using StudentPortal.Models;
namespace StudentPortal.Controllers;

public class StudentController : Controller
{
    public IActionResult Index()
    {
        var student = new Student
        {
            Id = 3,
            Marks = 23,
            Name = "Yogesh",
        };
        return View(student);
    }

    public IActionResult Details(int id)
    {
        return Content($"You requested student ${id}");
    }
}