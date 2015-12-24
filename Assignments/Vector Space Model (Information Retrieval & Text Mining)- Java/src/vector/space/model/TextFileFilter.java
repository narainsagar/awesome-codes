/*
....................... ASSIGNMENT NO # 02 ............................
....................... NAME : NARAIN SAGAR ............................
....................... COURSE : INFORMATION RETRIEVAL .................
....................... INSTRUCTOR : M. RAFI ............................
 */
package vector.space.model;

import java.io.File;
import java.io.FileFilter;

/**
 *
 * @author DARK-NINE(NARAIN SAGAR)
 */

public class TextFileFilter implements FileFilter {
    @Override
    public boolean accept(File pathname) {
        return pathname.getName().toLowerCase().endsWith("");
    }
}
