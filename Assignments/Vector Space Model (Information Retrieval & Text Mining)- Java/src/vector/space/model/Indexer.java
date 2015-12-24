/*
....................... ASSIGNMENT NO # 02 ............................
....................... NAME : NARAIN SAGAR ............................
....................... COURSE : INFORMATION RETRIEVAL .................
....................... INSTRUCTOR : M. RAFI ............................
 */
package vector.space.model;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileFilter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;
import org.apache.lucene.analysis.PorterStemFilter;
import org.apache.lucene.analysis.StopFilter;
import org.apache.lucene.analysis.TokenStream;
import org.apache.lucene.analysis.Tokenizer;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.analysis.standard.StandardFilter;
import org.apache.lucene.analysis.standard.StandardTokenizer;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.index.CorruptIndexException;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.store.Directory;
import org.apache.lucene.store.FSDirectory;
import org.apache.lucene.util.Version;

/**
 *
 * @author DARK-NINE(NARAIN SAGAR)
 */

public class Indexer {
    private final IndexWriter writer;
    Set<String> stopWords = new HashSet<>();
    
    public Indexer(String indexDirectoryPath) throws IOException{
        //this directory will contain the indexes
        Directory indexDirectory =
        FSDirectory.open(new File(indexDirectoryPath));
        //create the indexer
        writer = new IndexWriter(indexDirectory,
        new StandardAnalyzer(Version.LUCENE_36),true,
        IndexWriter.MaxFieldLength.UNLIMITED);
    }
    public void close() throws CorruptIndexException, IOException{
        writer.close();
    }
    private Document getDocument(File file) throws IOException{ 
       
        Document document = new Document(); 
        //index file contents
        Field contentField = new Field(LuceneConstants.CONTENTS,
        Stemmer_and_Stopword_Filter(file)); //new FileReader(file)
        
        //index file name
        Field fileNameField = new Field(LuceneConstants.FILE_NAME,
        file.getName(),
        Field.Store.YES,Field.Index.NOT_ANALYZED);
        //index file path
        Field filePathField = new Field(LuceneConstants.FILE_PATH,
        file.getCanonicalPath(),
        Field.Store.YES,Field.Index.NOT_ANALYZED);
        document.add(contentField);
        document.add(fileNameField);
        document.add(filePathField);
        return document;
    }
    private void indexFile(File file) throws IOException{
        //System.out.println("Indexing "+file.getCanonicalPath());
        Document document = getDocument(file);
        writer.addDocument(document);
    }
    
    public int createIndex(String dataDirPath, FileFilter filter) throws IOException{
        // Load and read stopwords file into Set...
        LoadStopWordsFromFileIntoSet();
        //get all files in the data directory
        File[] files = new File(dataDirPath).listFiles();
        for (File file : files) {
            if(!file.isDirectory()
            && !file.isHidden()
            && file.exists()
            && file.canRead()
            && filter.accept(file)
            ){
               indexFile(file);
            }
        }
        return writer.numDocs();
    }
    
    public void LoadStopWordsFromFileIntoSet() throws FileNotFoundException, IOException{
        FileReader stopReader = new FileReader("IRTM-A2\\Stopword-List.txt");
        BufferedReader bufferedReader = new BufferedReader(stopReader);
        String line;
        while ((line = bufferedReader.readLine()) != null) {
            line = line.toLowerCase();
            stopWords.add(line);
        }
    }
    public TokenStream Stemmer_and_Stopword_Filter(File file) throws FileNotFoundException{
        //  String fileText = new Scanner(file).useDelimiter("\\A").next();
        Tokenizer tok;
        tok = new StandardTokenizer(Version.LUCENE_36, new FileReader(file)); //new StringReader(fileText)
        StandardFilter standardFilter = new StandardFilter(Version.LUCENE_36, tok);
        StopFilter stopFilter = new StopFilter(Version.LUCENE_36, standardFilter, stopWords);
       
        TokenStream tokenStream = new PorterStemFilter(stopFilter);
        return (tokenStream);   
    }
}