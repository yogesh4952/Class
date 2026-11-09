namespace EfCorePractice;

using Microsoft.EntityFrameworkCore;


public class StudentService
{
    private readonly SchoolContext _context;

    public StudentService(SchoolContext context)
    {
        _context = context;
    }

    public Student CreateStudent(string name, int marks)
    {
        var student = new Student
        {
            Name = name,
            Marks = marks
        };

        _context.Students.Add(student);
        _context.SaveChanges();

        return student;
    }

    public List<Student> GetAllStudents()
    {
        return _context.Students.AsNoTracking().ToList();
    }

    public Student? GetStudentById(int id)
    {
        return _context.Students.Find(id);
    }

    public bool UpdateStudent(int id, string name, int marks)
    {
        var student = _context.Students.Find(id);

        if (student == null)
        {
            return false;
        }

        student.Name = name;
        student.Marks = marks;

        _context.SaveChanges();
        return true;
    }

    public bool DeleteStudent(int id)
    {
        var student = _context.Students.Find(id);

        if (student == null)
        {
            return false;
        }

        _context.Students.Remove(student);
        _context.SaveChanges();

        return true;
    }
}