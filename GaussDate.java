import static java.lang.System.out;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;

public class GaussDate{
    public static long daysBetween(LocalDate s,LocalDate e){
        return ChronoUnit.DAYS.between(s,e);
    }
    public static void main (String[] args) {
        if(args.length!=2){
            out.println("Usage: java GaussDate yyyymmdd num.");
            return;
        }
        DateTimeFormatter df = DateTimeFormatter.BASIC_ISO_DATE;
        LocalDate s = LocalDate.parse(args[0],df);
        //LocalDate e = LocalDate.parse(args[1],df);
        LocalDate e = s.plusDays(Long.parseLong(args[1]));
        out.println("[new date]:"+e);
    }
}
