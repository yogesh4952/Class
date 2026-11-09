using EfCorePractice;

using var context = new SchoolContext();

// Create the database and schema if the database does not exist.
context.Database.EnsureCreated();

var service = new StudentService(context);

// CREATE
var createdStudent = service.CreateStudent("Ram", 75);
Console.WriteLine($"Created student with ID {createdStudent.Id}");

// READ ALL
Console.WriteLine("\nStudent list:");

foreach (var student in service.GetAllStudents())
{
    Console.WriteLine(
        $"{student.Id} | {student.Name} | {student.Marks}");
}

// READ ONE
var foundStudent = service.GetStudentById(createdStudent.Id);

if (foundStudent != null)
{
    Console.WriteLine($"\nFound: {foundStudent.Name}");
}

// UPDATE
bool updated = service.UpdateStudent(
    createdStudent.Id, "Ram Sharma", 90);

Console.WriteLine($"\nUpdated: {updated}");

var updatedStudent = service.GetStudentById(createdStudent.Id);

if (updatedStudent != null)
{
    Console.WriteLine(
        $"{updatedStudent.Name} | {updatedStudent.Marks}");
}

// DELETE
bool deleted = service.DeleteStudent(createdStudent.Id);
Console.WriteLine($"\nDeleted: {deleted}");