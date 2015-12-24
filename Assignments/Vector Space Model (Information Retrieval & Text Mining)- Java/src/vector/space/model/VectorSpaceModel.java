/*
....................... ASSIGNMENT NO # 02 .............................
....................... NAME : NARAIN SAGAR ............................
....................... COURSE : INFORMATION RETRIEVAL .................
....................... INSTRUCTOR : M. RAFI ...........................
 */
package vector.space.model;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import org.apache.lucene.document.Document;
import org.apache.lucene.queryParser.ParseException;
import org.apache.lucene.search.ScoreDoc;
import org.apache.lucene.search.TopDocs;

/**
 *
 * @author DARK-NINE(NARAIN SAGAR)
 */

public class VectorSpaceModel{
    /**
     * @param args the command line arguments
     */    
    String indexDir = "IRTM-A2\\Indexes\\";
    String dataDir = "IRTM-A2\\Data_Doc50\\";
    Indexer indexer;
    Searcher searcher;
    public static void main(String[] args) {
        VectorSpaceModel tester;
        try {
            tester = new VectorSpaceModel();
            try {
			File Qfile;
                        Qfile = new File("IRTM-A2\\QueryList.txt");
                try (FileReader fileReader = new FileReader(Qfile)) {
                    BufferedReader bufferedReader = new BufferedReader(fileReader);
                    String qry;
                    int counter = 1;
                    while ((qry = bufferedReader.readLine()) != null) {
                        qry = qry.toLowerCase();
                        qry = qry.replaceAll("[^a-zA-Z0-9 ]", "");
                        System.out.println("\n--------------------------------------------------------------------------------------------------------------------------------------------");
                        System.out.println("Query No."+ (counter++) + " [\"" + qry +"\"]");
                        System.out.println("--------------------------------------------------------------------------------------------------------------------------------------------");
                        tester.createIndex();
                        tester.search(qry);
                        //  System.out.print("--------------------------------------------------------------------------------------------------------------------------------------------");
                    }
                }
		} catch (IOException e) {
			e.printStackTrace();
		} 
            } catch (ParseException e) {
            e.printStackTrace();
            }
    }
    private void createIndex() throws IOException{
        indexer = new Indexer(indexDir);
        int numIndexed;
        long startTime = System.currentTimeMillis();
        numIndexed = indexer.createIndex(dataDir, new TextFileFilter());
        long endTime = System.currentTimeMillis();
        indexer.close();
        System.out.println("Total " + numIndexed+" File indexed, time taken: " +(endTime-startTime)+" ms"); 
    }
    private void search(String searchQuery) throws IOException, ParseException{
        searcher = new Searcher(indexDir);
        long startTime = System.currentTimeMillis();
        TopDocs hits = searcher.search(searchQuery);
        long endTime = System.currentTimeMillis();
        System.out.println(hits.totalHits + " documents found. Time :" + (endTime - startTime));
        System.out.print("--------------------------------------------------------------------------------------------------------------------------------------------");
        System.out.println("\n      \t>>SCORE<<\t\t>>FileName<<\t\t>>FilePath<<");
        System.out.print("--------------------------------------------------------------------------------------------------------------------------------------------\n");
        int j=1;
        for(ScoreDoc scoreDoc : hits.scoreDocs) {
            Document doc = searcher.getDocument(scoreDoc);
            System.out.print("\t" + (j++) + " -> " + (Math.round(scoreDoc.score*1000.0)/1000.0) + "\t\t");
            System.out.print(doc.get(LuceneConstants.FILE_NAME) + "\t\t");
            System.out.println(doc.get(LuceneConstants.FILE_PATH));
        }
        searcher.close();
    }
    
}
