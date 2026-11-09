using Microsoft.EntityFrameworkCore;

namespace EfCorePractice;

public class SchoolContext : DbContext
{
    public DbSet<Student> Students => Set<Student>();

    protected override void OnConfiguring(
        DbContextOptionsBuilder optionsBuilder)
    {
        optionsBuilder.UseSqlite("Data Source=school.db");
    }
}